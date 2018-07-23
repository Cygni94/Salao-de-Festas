import React from "react";
import { BrowserRouter as Link } from "react-router-dom";
// react-router-dom replaces react-router in package.json dependencies.
// react-router 4.0.0 is a dependency of react-router-dom

const Header = () => {
    return (
        <nav className="navbar navbar-expand-lg navbar-light bg-light">
            <a className="navbar-brand" href="#">
                Navbar
            </a>
            <button
                className="navbar-toggler"
                type="button"
                data-toggle="collapse"
                data-target="#navbarTogglerDemo02">
                <span className="navbar-toggler-icon" />
            </button>

            <div className="collapse navbar-collapse" id="navbarTogglerDemo02">
                <ul className="navbar-nav mr-auto mt-2 mt-lg-0">
                    <li className="nav-item active">
                        <Link to="/">Home</Link>
                    </li>
                    <li className="nav-item">
                        <Link to="/clientes/cadastro">Cadastrar Cliente</Link>
                    </li>
                    <li className="nav-item">
                        <Link to="/funcionarios/cadastro">
                            Cadastrar Funcionário
                        </Link>
                    </li>
                </ul>
            </div>

            <hr />
            <form className="form-inline my-2 my-lg-0">
                <input
                    className="form-control mr-sm-2"
                    type="search"
                    placeholder="Search"
                />
                <button
                    className="btn btn-outline-success my-2 my-sm-0"
                    type="submit">
                    Search
                </button>
            </form>
        </nav>
    );
};

export default Header;
