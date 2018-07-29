import React, { Component } from "react";
import { connect } from "react-redux";
import { Field, reduxForm } from "redux-form";
import { createCliente } from "../actions/clientes";
import normalizePhone from "../vendor/normalizePhone";

class CadastroClientes extends Component {
    onSubmit(props) {
        console.log(props);
        this.props.createCliente(props, () => {
            this.props.history.push("/");
        });
    }

    renderField(field) {
        return (
            <div
                className={`form-group ${
                    field.meta.touched && field.meta.invalid ? "has-danger" : ""
                }`}>
                <label>{field.label}</label>
                <input {...field.input} type="text" className="form-control" />
                <div className="text-help">
                    {field.meta.touched ? field.meta.error : ""}
                </div>
            </div>
        );
    }

    render() {
        const { handleSubmit } = this.props;
        return (
            <div className="container">
                <form
                    className="col-md-5"
                    onSubmit={handleSubmit(this.onSubmit.bind(this))}>
                    <h3>Cadastrar novo cliente</h3>
                    <Field
                        label="Nome"
                        name="nome"
                        component={
                            this.renderField // this is a custom prop
                        }
                    />
                    <Field
                        label="Endereço"
                        name="endereco"
                        component={
                            this.renderField // this is a custom prop
                        }
                    />
                    <Field
                        label="Telefone"
                        name="phone"
                        type="text"
                        placeholder="Phone Number"
                        component={this.renderField}
                        normalize={normalizePhone}
                    />
                    <Field
                        label="Data de nascimento"
                        name="dataNasc"
                        type="date"
                        component={
                            this.renderField // this is a custom prop
                        }
                    />
                    <button type="submit" className="btn btn-primary">
                        Submit
                    </button>
                </form>
            </div>
        );
    }
}

function validate(values) {
    const errors = {};

    if (!values.title) {
        errors.title = "Enter a username";
    }
    if (!values.categories) {
        errors.categories = "Enter categories";
    }
    if (!values.content) {
        errors.content = "Enter some content";
    }

    return errors;
}

// reduxForm: 1st is form config
// connect: first argument is mapStateToProps, 2nd is mapDispatchToProps
export default reduxForm({
    form: "ClientesNewForm",
    validate,
})(
    connect(
        null,
        { createCliente }
    )(CadastroClientes)
);
