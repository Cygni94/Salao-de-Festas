import { combineReducers } from "redux";
import ClientesReducer from "./reducer_clientes";
import { reducer as formReducer } from "redux-form";

const rootReducer = combineReducers({
    posts: ClientesReducer,
    form: formReducer,
});

export default rootReducer;
